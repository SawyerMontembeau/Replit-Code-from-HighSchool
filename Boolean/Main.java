class Main {
  public static void main(String[] args) {
    System.out.println("Hello world!");
    boolean a = true;
    boolean b = false; 
    boolean c = !(!(a||b)&&(a&&b));
    System.out.println(c);
  }
}