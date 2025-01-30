import csv
from datetime import datetime
from matplotlib import pyplot as plt

filename = "sitka_weather_2014.csv" 

#open the file and call it 'f'
with open(filename) as f:
  #create a csv reader object
  reader = csv.reader(f)
  header_row = next(reader)
  print(header_row)

  #use an alternative for loop with the enumerate() function to automatically get the list element index and value without having to use for i in range()
  for index, column_header in enumerate(header_row):
    print(index,column_header)

  dates = []
  lows = []
  highs = []
  for row in reader:
    current_date = datetime.strptime(row[0],  "%Y-%m-%d")
    dates.append(current_date)
    high = int(row[1])
    highs.append(high)
    low = int(row[3])
    lows.append(low)

  fig = plt.figure(dpi = 128,figsize = (10,6), facecolor = "pink")
  plt.plot(dates,lows,c = "blue", alpha = 0.5)
  plt.plot(dates,highs,c = "red", alpha = 0.5)
  plt.fill_between(dates,highs,lows,facecolor = "green", alpha = 0.1)
  
  plt.title("Sitka Alaska: Daily high and low temperatures, 2014", fontsize = 24)
  plt.xlabel(" ",fontsize = 16)
  fig.autofmt_xdate()
  plt.ylabel("Temperature (F)", fontsize = 16)
  plt.tick_params(axis = 'both',which = "major",labelsize = 8)

  plt.show()