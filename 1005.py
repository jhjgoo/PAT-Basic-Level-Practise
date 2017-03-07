
covered = []
inarray = []


def callatz(num):
    while (num != 1 and num not in covered):
        covered.append(num)
        if(num % 2 == 0):
            num /= 2
        else:
            num = (3 * num + 1) / 2
    if(num != 1 and num in inarray):
        inarray.remove(num)
        return False
    return True

n = input()
str_in = input()
inarray = [int(n) for n in str_in.split()]

i = 0
while i < len(inarray):
    if callatz(inarray[i]):
        i += 1
inarray.sort(reverse=True)
outarray = [str(n) for n in inarray]
str_out = ' '.join(outarray)
print(str_out)
