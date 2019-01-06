public class Basic {
  public static void main(String[] argv) {
    System.out.println("smallest:" + new Native().instanceMethod(Native.classMethod()));
  }
}

class Native {
  static {
    System.loadLibrary("native");
  }
  public native int instanceMethod(int[] args);
  public static native int[] classMethod();
}
