def binary_search(T, n, p):

    table_len = len(T)

    while table_len > 0:

        middle = int(table_len/2)

        if T[middle] == p:
            return middle
        else:
            if T[middle]<p:
                T = T[middle:-1]
            else:
                T = T[0:middle]

        table_len = len(T)

    return -1

print(binary_search([1, 2, 3 ,4, 5], 4, 3))
