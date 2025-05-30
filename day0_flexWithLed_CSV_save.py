

import serial     # For serial communication
import csv        # To write data into CSV format
import time       # For timestamp-based filename

# Open serial connection to Arduino (update 'COM3' as per your system)
ser = serial.Serial('COM3', 9600, timeout=1)

# Generate a filename using current date and time
timestamp = time.strftime("%Y%m%d_%H%M%S")
filename = "flex_log_" + timestamp + ".csv"

# Open the CSV file in write mode
with open(filename, mode='w', newline='') as file:
    writer = csv.writer(file)
    
    # Write header row
    writer.writerow(["flexValue"])

    print("Recording... Press Ctrl+C to stop.")

    try:
        # Continuously read data from serial
        while True:
            # Read a line from serial, decode it, and remove whitespace
            line = ser.readline().decode().strip()

            # Check if line is a digit (valid sensor reading)
            if line.isdigit():
                # Convert to integer and write to CSV
                writer.writerow([int(line)])
    except KeyboardInterrupt:
        # When stopped with Ctrl+C, close serial and show filename
        print("Saved to " + filename)
        ser.close()




import csv  # To read the CSV file

# Set the name of the CSV file to read
filename = "flex_log_20250530_183000.csv"  # Replace with actual file name

# Open the CSV file
with open(filename, mode='r') as file:
    # Create a reader object that reads rows as dictionaries
    reader = csv.DictReader(file)

    # Create a list to store all flex values from the CSV
    values = [int(row['flexValue']) for row in reader]

    # Check if the list has any data
    if values:
        # Print minimum and maximum values
        print("Lowest value: " + str(min(values)))
        print("Highest value: " + str(max(values)))
    else:
        # Inform if file was empty
        print("No data found.")
