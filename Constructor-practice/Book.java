public class Book{

private String title;
private String genre;
private String author;
private int numPages;

public Book(){ //default constructor
  title = "" ;
  genre = "" ;
  author = "" ;
  numPages = 0;
}

public Book(String t, String g, String a, int np){ //overloaded constructor
  title = t ;
  genre = g ;
  author = a ;
  numPages = np;
}

public String getTitle(){ //getter | accessor method
 return title;
}

public String getGenre(){ //getter | accessor method
  return genre;
}

public String getAuthor(){ //getter | accessor method
  return author;
}

public int getNumPages(){ //getter | accessor method
  return numPages;
}

}