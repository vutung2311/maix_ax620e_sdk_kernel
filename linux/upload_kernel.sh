#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" &>/dev/null && pwd -P)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../../.." &>/dev/null && pwd -P)"

DIST_IP="${1:-}"
DIST_PATH="${2:-/tmp}"

if [ -z "$DIST_IP" ]; then
    echo "Usage: $(basename "$0") <target_ip> [target_path]"
    echo "Example: $(basename "$0") 192.168.10.70 /tmp"
    exit 1
fi

DIST_URL="root@${DIST_IP}:${DIST_PATH}"

DTB_FILE="${REPO_ROOT}/support/kernel/AX630C_emmc_arm64_k419_sipeed_nanokvm_signed.dtb"
BOOT_FILE="${REPO_ROOT}/support/kernel/boot_signed.bin"

if [ ! -f "$DTB_FILE" ] || [ ! -f "$BOOT_FILE" ]; then
    DTB_FILE="${REPO_ROOT}/build_dist/AX630C_emmc_arm64_k419_sipeed_nanokvm_signed.dtb"
    BOOT_FILE="${REPO_ROOT}/build_dist/boot_signed.bin"
fi

if [ ! -f "$DTB_FILE" ] || [ ! -f "$BOOT_FILE" ]; then
    echo "[*] Signed kernel binaries not found, building kernel..."
    bash "${REPO_ROOT}/support/scripts/build_kernel.sh" build
fi

echo "Uploading signed DTB and Boot binaries to ${DIST_URL}..."
scp "${DTB_FILE}" "${BOOT_FILE}" "${DIST_URL}/"
echo "[✓] Kernel binaries staged at ${DIST_URL}"