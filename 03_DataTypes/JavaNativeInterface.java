
public class JavaNativeInterface {
    static {
        final String file = System.getProperty("user.dir") + "/jni_impl.so";
        System.load( file );
    }

    public native long NewContext();
    public native void FreeContext( long handle );
    public native void Print( long handle );
    public native String GetStr( long handle );
    public native void SetStr( long handle, String s );

    static void psh( int n ) {
        System.out.println( "(Printing from Java) Square is: " + n );
    }

    public static void main(String[] args) {
        JavaNativeInterface obj = new JavaNativeInterface();
        long handle = obj.NewContext();

        final String tstr = "This String Created inside JAVA";

        obj.SetStr( handle, tstr );
        obj.Print( handle );
        String another = obj.GetStr( handle );

        System.out.println( "Java: \"" + another + "\"" );

        obj.FreeContext( handle );
    }
}

