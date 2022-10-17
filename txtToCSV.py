import pandas as pd
import numpy as np

def txtToCSV():
    state=["random","reversed","sorted"]
    size=["1000","3000","10000","30000","100000"]
    # algo=["SelectionSort","InsertionSort","BinaryInsertionSort","BubbleSort","ShakerSort",
    #      "ShellSort","HeapSort","MergeSort","QuickSort","CountingSort","RadixSort","FlashSort"]
    algo=["SelectionSort","InsertionSort","BubbleSort","ShakerSort",
        "ShellSort","MergeSort","QuickSort","RadixSort","FlashSort"]
    data=[[],[],[]]
    for sta in state:
        ToCSV=[]
        for siz in size:
            for alg in algo:
                path="C:\\Users\\trung\\OneDrive - VNU-HCMUS\\Attachments\\LapTrinh\\Nam2-1\\TH CTDL\\DSA_w3-5\\FILE\\New folder\\{}_{}_{}.txt".format(alg,sta,siz)
                f = open(path,"r")
                f.readline()
                ToCSV.append(f.readline())
        ToCSV=pd.DataFrame(np.array(ToCSV).reshape(5,-1),columns=algo)
        ToCSV.insert(0,"Size",size,True)
        ToCSV.to_csv("C:\\Users\\trung\\OneDrive - VNU-HCMUS\\Attachments\\LapTrinh\\Nam2-1\\TH CTDL\\DSA_w3-5\\FILE\\{}.csv".format(sta),index=False)
        print(ToCSV,"\n")

def main():
    txtToCSV()

if __name__=="__main__":
    main()