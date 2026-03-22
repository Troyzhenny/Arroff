# Arroff short for Arrow Off

A lightweight Windows utility to toggle the shortcut arrow overlay on desktop icons for a cleaner look.

## Features

- Remove or restore the shortcut arrow on Windows application shortcuts
- Simple single-screen CLI interface
- Instant effect via Explorer restart

## Requirements

- Windows 10 or 11
- Administrator privileges (required to write to the registry)

## Usage

1. Download the latest release
2. Right-click `arroff.exe` and select **Run as administrator**
3. Choose to remove or restore the arrow

## Building from Source
```bash
git clone https://github.com/Troyzhenny/Arroff.git
cd Arroff
mkdir build && cd build
cmake -G "Ninja" ..
cmake --build . --config Release
```

## How It Works

Arroff writes to `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Shell Icons`
and restarts Explorer to apply the change.

## License

MIT
