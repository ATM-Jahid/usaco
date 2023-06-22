def main():
    condx = []; condy = []
    with open('lineup.in', 'r') as f:
        for _ in range(int(f.readline())):
            tmp = f.readline().split()
            condx.append(tmp[0])
            condy.append(tmp[-1])

    cows = ["Bessie", "Buttercup", "Belinda", "Beatrice",
    		"Bella", "Blue", "Betsy", "Sue"]
    cows = sorted(cows)

    res = []
    while len(res) != 8:
        chain = 0
        if len(res):
            for c in cows:
                for j in range(len(condx)):
                    if (condx[j] == c and condy[j] == res[-1]) or \
                        (condy[j] == c and condx[j] == res[-1]):
                        res.append(c)
                        cows.remove(c)
                        chain = 1
                        break
                if (chain):
                    break

        if not chain:
            for c in cows:
                neigh = []
                for j in range(len(condx)):
                    if condx[j] == c and condy[j] not in res:
                        neigh.append(condy[j])
                    elif condy[j] == c and condx[j] not in res:
                        neigh.append(condx[j])
                if len(neigh) < 2:
                    res.append(c)
                    cows.remove(c)
                    break

    with open('lineup.out', 'w') as f:
        for i in res:
            f.write(i+'\n')

if __name__ == '__main__':
    main()
