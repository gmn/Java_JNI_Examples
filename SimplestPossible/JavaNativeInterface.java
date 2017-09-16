
public class JavaNativeInterface {
    static {
        // for use with explicit filenames. Must be absolute path.
        System.load("/home/gmn/code/baron/java/jni_impl.so");

        // for use with dll in the system library path
        //System.loadLibrary("jni_impl");
    }

    public native int printInt( int n );

    public static void main(String[] args) {
        JavaNativeInterface obj = new JavaNativeInterface();
        int ret = obj.printInt( 8 );
        System.out.println( "(Printing from Java) Int is: " + ret );
//        obj.printInt( 6 );
//        obj.printInt( 7 );
//        obj.printInt( 5 );
    }
}

