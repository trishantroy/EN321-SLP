#!/usr/bin/env python3

import matplotlib
import matplotlib.pyplot as plt
import csv

node_centrality_array = []
node_array = []

def get_data_from_files():
	with open("data_files/ieee_39_bus_system_node_centrality.csv",'r') as csvfile:
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
	ax.set_xlim([0,40])
	ax.set_ylim([0,0.25])
	ax.set_xlabel('Bus Number')
	ax.set_ylabel('Centrality index')
	ax.set_title('Centrality indices for IEEE 39 Bus System')
	fig.savefig('images/node_centrality')


if __name__ == '__main__':
	get_data_from_files()
	plot_results()	
	plt.show()