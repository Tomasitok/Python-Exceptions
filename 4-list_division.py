def list_division(my_list_1, my_list_2, list_length):

    result = []
    for i in range(list_length):
        try:
            num_1 = my_list_1[i]
            num_2 = my_list_2[i]
            div_result = num_1 / num_2
            result.append(div_result)
        except ZeroDivisionError:
            print("division by 0")
            result.append(0)
        except TypeError:
            print("wrong type")
            result.append(0)
        except IndexError:
            print("out of range")
            result.append(0)
        finally:
            pass
    return result
