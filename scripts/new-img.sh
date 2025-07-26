qemu-img create -f qcow2 -F qcow2 -b ../img/archpass-base-img.qcow2 img/$1.qcow2

sudo qemu-system-x86_64 \
  -enable-kvm \
  -m $2 \
  -drive file=img/$1.qcow2,format=qcow2,if=virtio \
  -netdev user,id=net0 \
  -device virtio-net,netdev=net0 \
  -nographic \
  -serial mon:stdio

