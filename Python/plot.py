import numpy as np
import matplotlib.pyplot as plt

# Generate some data
x = np.linspace(0, 2*np.pi, 100)  # Create an array of 100 evenly spaced values from 0 to 2*pi
y = np.sin(x)                     # Calculate the sine of each value in x

# Create the plot
plt.plot(x, y)

# Customize the plot
plt.title('Sine Wave')
plt.xlabel('x')
plt.ylabel('sin(x)')

# Display the plot
plt.show()
