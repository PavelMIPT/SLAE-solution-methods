import matplotlib.pyplot as plt
file = open("data_tau.txt")
file2 = open("data_t_opt.txt")
file3= open("data_chebysh.txt")
file4 = open("data_Simmetr_Gauss_Zeidel.txt")

y = file.read().split()
y2 = file2.read().split()
y3 = file3.read().split()
y4 = file4.read().split()

x = [i for i in range(len(y))]
x2 = [i for i in range(len(y2))]
x3 = [i for i in range(len(y3))]
x4 = [i for i in range(len(y4))]

for i in range(len(y)):
    y[i] = float(y[i])
for i in range(len(y2)):
    y2[i] = float(y2[i])
for i in range(len(y3)):
    y3[i] = float(y3[i])
for i in range(len(y4)):
    y4[i] = float(y4[i])

fig, ax = plt.subplots()

plt.plot(x, y, label = 'gradient with tau = 1/lmax')
plt.plot(x2, y2, label = 'gradient with tau = tau_opt')
plt.plot(x3, y3, label = 'gradient with chebyshov acceleration')
plt.plot(x4, y4, label = 'Simmetr Gauss Zeidel')

ax.legend()

plt.xlabel("номер итерации i")
plt.ylabel("логарифм невязки - ln(A * xi - b)")
plt.show()
