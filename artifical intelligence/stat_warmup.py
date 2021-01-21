import math
from collections import Counter

def mean(data):
    return sum(data) / len(data)

def median(data):
    data.sort()
    return (data[len(data) // 2] + data[len(data) // 2 - 1]) / 2 if len(data) % 2 == 0 else data[len(data) // 2]

def mode(data):
    highest = Counter(data).most_common()
    return sorted(highest, key=lambda x: (-x[1], x[0]))[0][0]

def standard_deviation(data):
    xbar = mean(data)
    return math.sqrt(sum([math.pow(item - xbar, 2) for item in data]) / len(data))

def confidence_interval(data):
    mu = mean(data)
    sigma = 1.96 * standard_deviation(data) / math.sqrt(len(data))
    return str(round(mu - sigma, 1)) + ' ' + str(round(mu + sigma, 1))

def main():
    length = int(input().strip())
    data = list(map(int, input().strip().split()))
    print(round(mean(data), 1), round(median(data), 1), mode(data), \
            round(standard_deviation(data), 1), confidence_interval(data), sep='\n')

if __name__ == '__main__':
    main()