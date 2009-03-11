@rem Step 1. Set command alias 
doskey bos=%ENLISTMENT_PROJ_ROOT%\src\Sample\Overshadow\build_code.bat

@rem Step 1. Set Sample - Overshadow environments
set SAMPLE_OVERSHADOW_NAME=Overshadow
set SAMPLE_OVERSHADOW_SRC_ROOT=%ENLISTMENT_PROJ_ROOT%\src\Sample\%SAMPLE_OVERSHADOW_NAME%
set SAMPLE_OVERSHADOW_BIN_ROOT=%ENLISTMENT_PROJ_ROOT%\bin\Sample\%SAMPLE_OVERSHADOW_NAME%
set SAMPLE_OVERSHADOW_LOG_ROOT=%SAMPLE_OVERSHADOW_BIN_ROOT%\log

@rem Final. Create Important bin path
if not exist %SAMPLE_OVERSHADOW_BIN_ROOT% mkdir %SAMPLE_OVERSHADOW_BIN_ROOT%
if not exist %SAMPLE_OVERSHADOW_LOG_ROOT% mkdir %SAMPLE_OVERSHADOW_LOG_ROOT%