def safe_print_list_integers(my_list=[], x=0):

    count = 0

    try:
        for element in my_list[:x]:
            try:
                print("{:d}".format(element), end="")
                count += 1
            except (ValueError, TypeError):
                pass
    except (IndexError, ValueError, TypeError):
        pass
    finally:
        print()
        return count