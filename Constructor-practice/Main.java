class Main {
  public static void main(String[] args) {
    
    Book b = new Book("The Wonders of Cheese", "Philosophy and Insight", "Gerald J. Donovan", 67820);

    System.out.println("The book's title is: " + b.getTitle() + "\nThe book's genre is: " + b.getGenre() + "\nThe book's author is: " + b.getAuthor() + "\nThe book's number of pages is: " + b.getNumPages());
  }
}