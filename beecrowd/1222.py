import sys, threading
import math
def main1():
        values = input('')
        while(values!='EOF'): 
            max_words, max_line_page, max_caractere_line = map(int, values.split())
            short_story = input('')
            short_story = short_story.split(' ')
            short_story = [x for x in short_story if x != '']
            pages = 1
            line = 0
            for word in short_story:
                    if (len(word) + line <= max_caractere_line):
                            line += len(word) + 1
                    else:
                            pages += 1
                            line = len(word) + 1
            pages = math.ceil(pages / max_line_page)
            print(pages)
            values = input('')
if __name__ == "__main__":
    sys.setrecursionlimit(9100000)
    threading.stack_size(134217728)
    main_thread = threading.Thread(target=main1)
    main_thread.start()
    main_thread.join()