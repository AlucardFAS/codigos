from Model import *
from csv import reader

def load_csv(filename):
	dataset = list()
	with open(filename, 'r') as file:
		csv_reader = reader(file)
		for row in csv_reader:
			if not row:
				continue
			dataset.append(row)
	return dataset

def main():
    data = load_csv('myterrain.csv')
    print(data)

if __name__ == "__main__":
    main()