
sudo qemu-system-x86_64 \
  -enable-kvm \
  -m $2 \
  -drive file=img/$1.qcow2,format=qcow2,if=virtio \
  -netdev user,id=net0 \
  -device virtio-net,netdev=net0 \
  -nographic \
  -serial mon:stdio

