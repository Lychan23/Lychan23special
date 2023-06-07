import matplotlib.pyplot as plt

categories = ['A', 'B', 'C', 'D']
sizes = [30, 15, 45, 10]

plt.pie(sizes, labels=categories, autopct='%1.1f%%')
plt.title('Pie Chart')
plt.show()
