
public class JavaNativeInterface {
    static {
        String file = System.getProperty("user.dir");
        file += "/jni_impl.so";
        System.out.println("loading: \"" + file + "\"" );

        // use load when loading from explicit file path
        System.load( file );

        // use loadLibrary when loading from system library path
        //System.loadLibrary("jni_impl");
    }

    public native int printInt( int n );

    static void psh( int n ) {
        System.out.println( "(Printing from Java) Square is: " + n );
    }

    public static void main(String[] args) {
        JavaNativeInterface obj = new JavaNativeInterface();
        psh( obj.printInt( 8 ) );
        psh( obj.printInt( 6 ) );
        psh( obj.printInt( 7 ) );
        psh( obj.printInt( 5 ) );
    }
}

