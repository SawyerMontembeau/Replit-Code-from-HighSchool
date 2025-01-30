import matplotlib.pyplot as plt

input_values = [1,2,3,4,5]
squares = []
for i in input_values:
  squares.append(i*i)
  
plt.plot(input_values,squares,linewidth = 5)
plt.title("Square Numbers", fontsize = 24)
plt.xlabel("Value", fontsize = 14)
plt.ylabel("Squared Value", fontsize = 14)
plt.tick_params(axis = "both", labelsize = 14)
plt.show()