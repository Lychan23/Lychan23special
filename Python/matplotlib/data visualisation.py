import matplotlib.pyplot as plt
import numpy as np

def line_plot(x, y):
    plt.plot(x, y)
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('Line Plot')
    plt.show()

def scatter_plot(x, y, colors=None, sizes=None):
    if colors is None:
        colors = 'b'
    if sizes is None:
        sizes = 20

    plt.scatter(x, y, c=colors, s=sizes, alpha=0.7, cmap='viridis')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('Scatter Plot')
    plt.colorbar()
    plt.show()

def bar_chart(categories, values):
    plt.bar(categories, values)
    plt.xlabel('Categories')
    plt.ylabel('Values')
    plt.title('Bar Chart')
    plt.show()

def histogram(data, bins=10):
    plt.hist(data, bins=bins)
    plt.xlabel('Value')
    plt.ylabel('Frequency')
    plt.title('Histogram')
    plt.show()

def pie_chart(categories, sizes):
    plt.pie(sizes, labels=categories, autopct='%1.1f%%')
    plt.title('Pie Chart')
    plt.show()

def box_plot(data):
    plt.boxplot(data)
    plt.xlabel('Data')
    plt.title('Box Plot')
    plt.show()

# Example usage:
x = np.linspace(0, 10, 100)
y = np.sin(x)

line_plot(x, y)

x = np.random.rand(100)
y = np.random.rand(100)
colors = np.random.rand(100)
sizes = 100 * np.random.rand(100)

scatter_plot(x, y, colors, sizes)

categories = ['A', 'B', 'C', 'D']
values = np.random.rand(len(categories))

bar_chart(categories, values)

data = np.random.randn(1000)
histogram(data)

categories = ['A', 'B', 'C', 'D']
sizes = [30, 15, 45, 10]

pie_chart(categories, sizes)

data = np.random.randn(100)

box_plot(data)
