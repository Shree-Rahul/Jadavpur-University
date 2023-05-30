numbers = [ x for x in range(1,50)]
multiples_of_five = list(filter(lambda x: x % 5 == 0,numbers))
print(multiples_of_five)