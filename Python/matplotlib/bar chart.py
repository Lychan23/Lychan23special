import matplotlib.pyplot as plt
import numpy as np

categories = ['A', 'B', 'C', 'D']
values = np.random.rand(len(categories))

plt.bar(categories, values)
plt.xlabel('Categories')
plt.ylabel('Values')
plt.title('Bar Chart')
plt.show()
