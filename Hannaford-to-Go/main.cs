using System.Collections;
using System;

class Program {
  public static void Main (string[] args) {
    Console.WriteLine("How many carts would you like to enter?");
    int amtCarts = Convert.ToInt32(Console.ReadLine());
    Cart[] carts = new Cart[amtCarts];

  for(int i = 0; i < amtCarts; i++){
    bool end = false;
    carts[i] = new Cart();
    while(end==false){
      Console.WriteLine("\nEnter the number of what you would like to do first");
      Console.WriteLine("1: Add Item to Cart");
      Console.WriteLine("2: Add up prices of Items in Cart");
      Console.WriteLine("3: List items added to cart");
      Console.WriteLine("4: End\n");
      int ans = Convert.ToInt32(Console.ReadLine());
      
      if(ans == 1){
        carts[i].printAllItems();
        Console.WriteLine("\nEnter the index of the item you'd like to add to the cart:");
        int item = Convert.ToInt32(Console.ReadLine());
        carts[i].addItem(item);
      }else if(ans == 2){
        carts[i].priceSum();
      }else if(ans == 3){
        carts[i].printCart();
      }else if(ans == 4){
        Console.WriteLine("\nCart #" + (i+1) + " is Complete!\n");
        end = true;
      }else{
        Console.WriteLine("\nINVALID OPTION\n");
      }
    }
  }
   
  }
}

class Cart{
  //state variables, possible items to add to cart and corresponing prices
  string[] items = new string[20];
  double[] prices = new double[20];


  //state variables, empty array lists for stored items and corresponding prices
  ArrayList cartItems = new ArrayList();
  ArrayList cartPrices = new ArrayList();
  
//constructor for Cart Class
  public Cart(){
    items[0] = "bread";
    prices[0] = 2.5;
    items[1] = "milk";
    prices[1] = 3.5;
    items[2] = "cheese";
    prices[2] = 1.5;
    items[3] = "apples";
    prices[3] = 3;
     items[4] = "lettuce";
    prices[4] = 4;
     items[5] = "spaghetti";
    prices[5] = 3;
     items[6] = "ramen noodles";
    prices[6] = 1.5;
    items[7] = "rice";
    prices[7] = 2;
    items[8] = "frozen pizza";
    prices[8] = 6;
    items[9] = "ice cream";
    prices[9] = 4.5;
    items[10] = "apple juice";
    prices[10] = 2.5;
    items[11] = "cheez its";
    prices[11] = 4;
    items[12] = "flour";
    prices[12] = 2.5;
    items[13] = "sugar";
    prices[13] = 2;
    items[14] = "baking soda";
    prices[14] = 1.5;
     items[15] = "vanilla extract";
    prices[15] = 4;
     items[16] = "strawberries";
    prices[16] = 3.5;
     items[17] = "chocolate chips";
    prices[17] = 2;
    items[18] = "frosting";
    prices[18] = 2.5;
    items[19] = "quail eggs";
    prices[19] = 30;
  }

  //prints all possible items that can be added to cart.
  public void printAllItems(){
    for(int i = 0; i<items.Length;i++){
      Console.WriteLine(i + ": " + items[i] + " $" + prices[i]);
    }
  }

  //returns the item of the inputted index
  public string returnItem(int index){
    return items[index];
  }

  //returns the price of the item in the inputted index
  public double returnPrice(int index){
    return prices[index];
  }

  //adds an item from the items list into the cart's arralist inventory
  public void addItem(int item){
    cartItems.Add(items[item]);
    cartPrices.Add(prices[item]);
  }

  //prints out all the items added to the cart
  public void printCart(){
    Console.WriteLine("\nThe items in the cart are:");
    for(int i = 0; i<cartItems.Count; i++){
      Console.WriteLine(cartItems[i] + " $" + cartPrices[i]);
    }
    Console.WriteLine("\n");
  }

  //sums up all of the prices of items added to the cart
  public void priceSum(){
    double sum = 0;
    for(int i = 0; i<cartPrices.Count; i++){
    sum += Convert.ToDouble(cartPrices[i]);
    }
    Console.WriteLine("\nThe total for the cart is $" + sum + "\n");
  }
   
}