FLAGS="-Wall -Wextra -Wpedantic"
PREF=jni_impl

INC=-I/usr/lib/jvm/java-7-openjdk-amd64/include
INC="$INC ${INC}/linux"
INC="$INC -I/usr/lib/jvm/java-8-openjdk-amd64/include"
INC="$INC ${INC}/linux"

function EE() {
    echo "$@"
    $@
}

if [ "x$@" == "xclean" ]; then
    echo "cleaning..."
    EE rm JavaNativeInterface.class JavaNativeInterface.h jni_impl.o jni_impl.so
    exit 0
fi

EE javac JavaNativeInterface.java
EE javah JavaNativeInterface

EE gcc $FLAGS -fPIC ${INC} ${PREF}.c -c
EE gcc -shared ${PREF}.o -o ${PREF}.so

echo
echo -n "running: "
EE java JavaNativeInterface
