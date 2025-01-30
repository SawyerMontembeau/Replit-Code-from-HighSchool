class Main {
  public static void main(String[] args) {
    int a[][] = { {1,2,-2,0},
                  {-3,4,7,2},
                  {6,0,3,1}};
    
    int b[][] = { {-1,3},
                  {0,9},
                  {1,-11},
                  {4,-5}};

    for(int i = 0; i < a.length; i++){
      for(int j = 0; j < b[0].length; j++){
        System.out.print(matrixMult.mult(a,b)[i][j] + ",");
      
      }
      System.out.println();
    }   

  }
}