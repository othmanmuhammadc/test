#!/bin/bash

echo "🔐 AutoHack - Installation Script"
echo "=================================="

# Check if running as root
if [ "$EUID" -ne 0 ]; then
    echo "[!] Please run as root (use sudo)"
    exit 1
fi

echo "[+] Updating package list..."
apt update

echo "[+] Installing required tools..."
apt install -y bettercap dsniff iptables python3 python3-pip

echo "[+] Making scripts executable..."
chmod +x autohack.py

echo "[+] Creating payload directory..."
mkdir -p payloads

echo "[+] Checking file permissions..."
ls -la *.py *.bat *.sh

echo "[+] Testing Python dependencies..."
python3 -c "import subprocess, threading, http.server, socketserver; print('✓ Python dependencies OK')"

echo "[+] Installation complete!"
echo ""
echo "Usage:"
echo "  sudo python3 autohack.py --target <TARGET_IP>"
echo ""
echo "Example:"
echo "  sudo python3 autohack.py --target 192.168.1.2"
echo ""
echo "Remember to start your Netcat listener:"
echo "  nc -lvnp 9999" 





