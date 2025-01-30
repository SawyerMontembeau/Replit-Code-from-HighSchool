class Main {
  public static void main(String[] args) {
 String s1 = "Allan Alda";
 String s2 = "John Wayne";
 String s3 = "Gregory Peck";
 String ss1 = s1 + ">>>" + s1.substring(2,7) ;
 String ss2 = s2 + ">>>" + s2.substring(2,7) ;
 String ss3 = s3 + ">>>" + s3.substring(2,9) ;
 System.out.print(ss1+"\n"+ss2+"\n"+ss3);
  }
}