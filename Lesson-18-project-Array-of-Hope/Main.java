class Main {
  public static void main(String[] args) {
    char ch[] = new char[26];
      
for(int i=65,x=0; i<=90; i++,x++){
  ch[x] = (char)i; 
      }
for(int i=0;i<=25;i++){
  if(i<24){
  System.out.print(ch[i] + ", ");
}else if(i==25){
  System.out.print(ch[25]);
}
    }
  }
}