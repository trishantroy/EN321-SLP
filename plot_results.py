#!/usr/bin/env python3

import matplotlib
import matplotlib.pyplot as plt
import csv
from statistics import mean, stdev

node_centrality_array = []
node_array = []

def get_data_from_files():
	with open("data_files/ieee_118_bus_system_node_centrality.csv",'r') as csvfile:
		plots = csv.reader(csvfile, delimiter=',')
		for row in plots:
			node_array.append(float(row[0]))
			node_centrality_array.append(float(row[1]))

def plot_results():
	fig = plt.figure(1)
	ax = fig.add_subplot(111)

	# ax.scatter(node_array, node_centrality_array)
	markerline, stemline, baseline, = ax.stem(node_array, node_centrality_array)
	plt.setp(markerline, markersize = 3)
	ax.set_xlim([0,120])
	ax.set_ylim([0,0.15])
	ax.set_xlabel('Bus Number')
	ax.set_ylabel('Centrality index')
	ax.set_title('Centrality indices for IEEE 118 Bus System')
	fig.savefig('images/node_centrality_118')

def get_attacks_data():
	random_attacks_data = []
	target_attacks_data = []

	with open("data_files/attacks_data.csv",'r') as csvfile:
		plots = csv.reader(csvfile, delimiter=',')
		for row in plots:
			data = []
			for i in range(len(row)-2):
				data.append(float(row[i+1]))
			if row[0] == "Random":
				random_attacks_data.append(data)
			elif row[0] == "Targeted":
				target_attacks_data = data

	random_attacks_mean, random_attacks_sd = [], []
	for i in range(len(random_attacks_data[0])):
		data1 = [a[i] for a in random_attacks_data]
		random_attacks_mean.append(mean(data1))
		random_attacks_sd.append(stdev(data1))
	# print(random_attacks_sd)
	x_data = [(i+1) for i in range(len(random_attacks_mean))]
	fig = plt.figure(2)
	ax = fig.add_subplot(111)
	ax.plot(x_data, random_attacks_mean, label='Random Attacks')
	ax.scatter(x_data, random_attacks_mean)
	ax.plot(x_data, target_attacks_data, label = 'Targeted Attacks')
	ax.scatter(x_data, target_attacks_data)
	ax.errorbar(x_data, random_attacks_mean, yerr=random_attacks_sd, alpha=0.5, ecolor='black')
	ax.set_xlim([1,len(random_attacks_mean)])
	ax.set_ylim([50,100])
	ax.set_xlabel('Number of attacks')
	ax.set_ylabel('Maximum flow capacity (%)')
	ax.set_title('Effect of attacks on maximum flow')
	ax.grid()
	fig.savefig('images/attacks.png')

if __name__ == '__main__':
	# get_data_from_files()
	# plot_results()
	get_attacks_data()
	plt.show()