
public class JavaNativeInterface {
    static {
        final String file = System.getProperty("user.dir") + "/jni_impl.so";
        System.load( file );
    }

    public native long NewContext();
    public native void FreeContext( long ctx );
    public native void Print();
    public native void Push( long handle, String s );
    public native String GetStr();

    static void psh( int n ) {
        System.out.println( "(Printing from Java) Square is: " + n );
    }

    public static void main(String[] args) {
        JavaNativeInterface obj = new JavaNativeInterface();
        long ctx = obj.NewContext();
        System.out.println( "Java got : " + Long.toHexString( ctx ) );
        obj.FreeContext( ctx );
    }
}

