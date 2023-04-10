import matplotlib.pyplot as plt
file = open("data_tau.txt")
file2 = open("data_t_opt.txt")
file3= open("data_chebysh.txt")

y = file.read().split()
y2 = file2.read().split()
y3 = file3.read().split()

x = [i for i in range(len(y))]
x2 = [i for i in range(len(y2))]
x3 = [i for i in range(len(y3))]

for i in range(len(y)):
    y[i] = float(y[i])
for i in range(len(y2)):
    y2[i] = float(y2[i])
for i in range(len(y3)):
    y3[i] = float(y3[i])

plt.plot(x, y)
plt.plot(x2, y2)
plt.plot(x3, y3)

plt.xlabel("логарифм невязки - ln(A * xi - b)")
plt.ylabel("номер итерации i")
plt.show()
