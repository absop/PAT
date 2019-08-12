
def tominute(time):
    day, hour, minute = time
    return (day * 24 + hour) * 60 + minute

def bill(time):
    day, hour, minute = time
    charge = day * rate[24]
    charge += sum(rate[:hour])
    charge += rate[hour] * minute / 60.0
    return charge

customer, paired = {}, []
rate = [0.6 * int(i) for i in input().split(" ")]
rate.append(sum(rate))

for i in range(int(input())):
    name, time, status = input().split(" ")

    if name not in customer:
        customer[name] = []

    customer[name].append((time, status == "on-line"))

for name in sorted(customer):
    record = customer[name]
    record.sort(key=lambda x: x[0])
    i, pair = 1, []
    while i < len(record):
        if not record[i][1]:
            if record[i - 1][1]:
                pair.append(i)
            i += 1
        i += 1
    if pair:
        paired.append((name, pair))

for name, pair in paired:
    total = 0
    record = customer[name]
    print(name, record[0][0][:2])
    for i in pair:
        t1, t2 = record[i - 1][0][3:], record[i][0][3:]
        time1 = [int(i) for i in t1.split(":")]
        time2 = [int(i) for i in t2.split(":")]
        minute = tominute(time2) - tominute(time1)
        once =  bill(time2) - bill(time1)
        total += once
        print(t1, t2, minute, "$%.2f"%once)
    print("Total amount: $%.2f"%total)
