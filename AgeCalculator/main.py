#import tkinter and other libraries
import tkinter as tk
import datetime
from PIL import Image, ImageTk



#define function called getInput() that takes in the users birthday, and calculates their age
def getInput():
    name = nameEntry.get()
    year = int(yearEntry.get())
    month = monthEntry.get().title()
    date = int(dateEntry.get())

    #Create a lost called months and set it equal to the months of the year as strings
    months = [
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    ]
    #Create a variable called monthIndex and set it equal to the index of the month in the list that the user entered
    monthIndex = months.index(month) + 1
    birthday = datetime.date(year, monthIndex, date)
    today = datetime.date.today()

    age = today.year - birthday.year

    #Create a text Widget that will display a customer message
    textArea = tk.Text(master=window,
                       bg="lightblue",
                       fg="black",
                       height=5,
                       width=35,
                       font="Helvetica")
    textArea.grid(column=1, row=6)
    answer = "Hey {0}! you are {1} years old!".format(name.title(), age)
    textArea.insert(tk.END, answer)


#Create a tkinter window
window = tk.Tk()
window.geometry("620x780")
window.title("Age Calculator App")

#Create labels using .Label() tkinter method
name = tk.Label(text="Name")
name.grid(column=0, row=1)
year = tk.Label(text="Year")
year.grid(column=0, row=2)
month = tk.Label(text="Month")
month.grid(column=0, row=3)
date = tk.Label(text="Date")
date.grid(column=0, row=4)

#Create some entry fields using .Entry method
nameEntry = tk.Entry()
nameEntry.grid(column=1, row=1)
yearEntry = tk.Entry()
yearEntry.grid(column=1, row=2)
monthEntry = tk.Entry()
monthEntry.grid(column=1, row=3)
dateEntry = tk.Entry()
dateEntry.grid(column=1, row=4)

#Create a button  that runs the .getInput() function when we click it
button = tk.Button(window,
                   text="Calculate your Age!",
                   command=getInput,
                   bg="purple",
                   fg="White",
                   font="Helvetica")
button.grid(column=1, row=5)

#Set an image in the window
image = Image.open("mountain.png")
image.thumbnail((200, 200), Image.ANTIALIAS)
photo = ImageTk.PhotoImage(image)
label_image = tk.Label(image=photo)
label_image.grid(column=1, row=0)
