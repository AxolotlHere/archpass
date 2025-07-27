# ArchPass

A simple command-line tool for managing Arch Linux virtual machines using QEMU/KVM.

## Overview

ArchPass provides an easy way to create, boot, and manage Arch Linux virtual machines. It uses QEMU with KVM acceleration for optimal performance and includes convenient scripts for VM lifecycle management.

## Features

- Create new Arch Linux VMs from a base image
- Boot existing VMs with custom RAM allocation
- List all available VM images
- Delete VM images
- KVM acceleration support
- Virtio drivers for better performance

## Prerequisites

- Linux system with KVM support
- QEMU installed (`qemu-system-x86_64`)
- Root/sudo access for installation
- Base Arch Linux image (see Installation section)

## Installation

1. **Download the base image:**

   ```bash
   # Download archpass-base-img.qcow2 from https://gofile.io/d/mwp9Ts
   # Place it in the img/ directory of this project
   ```

2. **Run the installation script:**

   ```bash
   chmod +x install.sh
   ./install.sh
   ```

   The installation script will:

   - Check for the base image
   - Move the project to `/usr/archpass/`
   - Set proper permissions on scripts
   - Create a symlink to `/usr/local/bin/archpass`

## Usage

### Create a new VM

```bash
archpass new <vm-name> <ram-size>
```

Example:

```bash
archpass new myvm 4G
```

### Boot an existing VM

```bash
archpass boot <vm-name> <ram-size>
```

Example:

```bash
archpass boot myvm 4G
```

### List all VMs

```bash
archpass list
```

### Delete a VM

```bash
archpass del <vm-name>
```

## File Structure

```
/usr/archpass/
├── src/
│   └── archpass          # Main binary
├── scripts/
│   ├── new-img.sh        # Create new VM script
│   ├── boot-img.sh       # Boot VM script
│   └── del-img.sh        # Delete VM script
├── img/
│   └── *.qcow2          # VM image files
└── install.sh           # Installation script
```

## Technical Details

### VM Configuration

- **Virtualization:** KVM acceleration enabled
- **Storage:** QCOW2 format with virtio interface
- **Network:** User-mode networking (NAT)
- **Console:** Serial console (no GUI)
- **RAM:** Configurable per VM instance

### Base Image

The base image (`archpass-base-img.qcow2`) should be a pre-configured Arch Linux installation. New VMs are created by copying this base image.

## Commands Reference

| Command | Description                     | Arguments              |
| ------- | ------------------------------- | ---------------------- |
| `new`   | Create a new VM from base image | `<vm-name> <ram-size>` |
| `boot`  | Boot an existing VM             | `<vm-name> <ram-size>` |
| `list`  | Show all available VMs          | None                   |
| `del`   | Delete a VM image               | `<vm-name>`            |

## RAM Size Format

- Use standard suffixes: `1G`, `2G`, `4G`, `512M`, etc.
- Examples: `2G` (2 gigabytes), `1536M` (1.5 gigabytes)

## Troubleshooting

### Common Issues

**"No such file or directory" when booting:**

- Ensure the VM image exists in `/usr/archpass/img/`
- Check that the image name is correct (use `archpass list`)

**"Permission denied" errors:**

- Make sure scripts have execute permissions
- Verify you have sudo access if needed

**KVM not available:**

- Check if KVM is enabled: `lsmod | grep kvm`
- Ensure your CPU supports virtualization
- Check BIOS/UEFI settings for VT-x/AMD-V

**Base image not found during installation:**

- Download the base image from the provided link
- Place it in the `img/` directory before running install.sh

### Accessing VMs

- VMs boot with serial console output
- Use Ctrl+A, X to exit QEMU console
- For SSH access, configure networking in the guest OS

## Development

### Building from Source

```bash
gcc -o src/archpass src/archpass.c
```

### Script Locations

All scripts use absolute paths to `/usr/archpass/` for system-wide installation compatibility.

## License

This project is provided as-is for educational and development purposes.

## Contributing

Feel free to submit issues, feature requests, or pull requests to improve ArchPass.
