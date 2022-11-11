@echo off

REM
REM Different tracing options that can be enabled
REM
REM SET XXX=(GUID|KnownProviderName)[:(Flags|Groups)[:Level[:'stack']]]
set TRACE_DXC=802ec45a-1e99-4b83-9920-87c98277ba9d:0x100845:5
set TRACE_DXC_ALL=802ec45a-1e99-4b83-9920-87c98277ba9d:0xffffffffffffffff:5
set TRACE_D3D12=5d8087dd-3a9b-4f56-90df-49196cdc4f11:0xffffffffffffffff:6
set TRACE_D3D11=db6f6ddb-ac77-4e88-8253-819df9bbf140:0xffffffffffffffff:6
set TRACE_UMD=a688ee40-d8d9-4736-b6f9-6b74935ba3b1:0xffff:5

if not "%TLOG%"=="" goto Done_With_It
REM 
REM To determine physical memory
REM
if not "%TRACE_LOGGING_MEMORY%" == "" goto Do_Not_Process_File
systeminfo > me.txt
findstr /sipn /C:"Total Physical Memory" me.txt > me2.txt
REM TRACE_LOGGING_MEMORY will hold the amount of physical memory on this machine.
for /f "tokens=6 delims=: " %%a in (me2.txt) do set TRACE_LOGGING_MEMORY=%%a
del me.txt
del me2.txt
set TRACE_LOGGING_MEMORY=%TRACE_LOGGING_MEMORY:,=%
:Do_Not_Process_File

REM
REM For buffers sizes
REM
REM The cutoff for large bufers 5G, Medium buffers 2G physical memory
if %TRACE_LOGGING_MEMORY% Gtr 4000 goto Set_Large_Buffers
if %TRACE_LOGGING_MEMORY% Gtr 2000 goto Set_Medium_Buffers
REM echo !Using Small Buffers Memory Footprint here!
set TRACE_LARGE_BUFFERS=-BufferSize 1024 -MinBuffers 30 -MaxBuffers 120
set TRACE_STAND_BUFFERS=-BufferSize 1024 -MinBuffers 25 -MaxBuffers 25
goto Done_With_It
:Set_Medium_Buffers
REM echo !Using Meidum Buffers Memory Footprint here!
set TRACE_LARGE_BUFFERS=-BufferSize 1024 -MinBuffers 60 -MaxBuffers 240
set TRACE_STAND_BUFFERS=-BufferSize 1024 -MinBuffers 50 -MaxBuffers 50
goto Done_With_It
:Set_Large_Buffers
REM echo !Using Large Buffers Memory Footprint here!
set TRACE_LARGE_BUFFERS=-BufferSize 1024 -MinBuffers 120 -MaxBuffers 480
set TRACE_STAND_BUFFERS=-BufferSize 1024 -MinBuffers 100 -MaxBuffers 100
:Done_With_It

REM
REM NT logging groupings
REM 
set TRACE_NT=PROC_THREAD

REM
REM The Environment variable TLOG (trace logging) will be used to indicate that
REM logging is active or not. if TLOG is set to ON, we're currently logging.
REM 

if "%TLOG%"=="" goto StartSection
if "%TLOG%"=="NORMAL" goto StopSection

REM Start Logging section
:StartSection

if %errorlevel% GTR 0 goto OSUsage
"%~dp0"..\Xperf -on %TRACE_NT% %TRACE_LARGE_BUFFERS% -f Kernel.etl
"%~dp0"..\Xperf -start DxcLogger -on %TRACE_DXC%+%TRACE_D3D11%+%TRACE_D3D12%+%TRACE_UMD% %TRACE_LARGE_BUFFERS% -f DXC.etl
"%~dp0"..\Xperf -capturestate DxcLogger %TRACE_DXC_ALL%+%TRACE_D3D11%+%TRACE_D3D12%+%TRACE_UMD%
set TLOG=NORMAL
goto EndIt



REM Stop Logging section
:StopSection

"%~dp0"..\Xperf -stop DxcLogger
"%~dp0"..\Xperf.exe -stop
echo All loggers stopped, starting merge...
"%~dp0"..\Xperf -merge DXC.etl kernel.etl Merged.etl
echo Restoring Performance Counter Interval
"%~dp0"..\Xperf -setprofint
set TLOG=
goto EndIt


REM
REM Error message section.
REM

:OSUsage
echo Error: Logging should be done on Vista capable OS.
goto EndIt

:CLUsage
echo Error: Invalid command line argument.
goto EndIt

:EndIt
@echo on

