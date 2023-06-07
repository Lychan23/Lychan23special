import matplotlib.pyplot as plt
import numpy as np

data = np.random.randn(100)

plt.boxplot(data)
plt.xlabel('Data')
plt.title('Box Plot')
plt.show()
