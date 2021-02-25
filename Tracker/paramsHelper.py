import os, json, sys
import pandas as pd

# Creates an empty run.num file
def createRunNum() -> str:
    with open(f"run.num", "w") as f:
        sys.stdout = f
        print("0")
        sys.stdout = sys.__stdout__

# Outputs a params str which can be converted to a file 
def print_params(param_ops: dict, ver: int) -> str:
    with open(f"params-{ver}", "w") as f:
        sys.stdout = f
        print(f"Rerun                   -1")
        print(f"Print_params            1")
        print(f"Max_steps		{param_ops['Max_steps']}")
        print(f"Pop_size                {param_ops['Pop_size']}")
        print(f"Init_thresh 		{param_ops['Init_thresh']}")
        print(f"Thresh_increase		0.1")
        print(f"Thresh_decrease		0.1")
        print(f"Max_thresh		1.0")
        print(f"Min_thresh		0.0")
        print(f"Prob_check		1.0")
        print(f"Task_selection		{param_ops['Task_selection']}")
        print(f"Target_path		{param_ops['Target_path']}")
        print(f"Path_amplitude		{param_ops['Path_amplitude']}")
        print(f"Path_period		{param_ops['Path_period']}")
        print(f"Target_step_len		{param_ops['Target_step_len']}")
        print(f"Range			{param_ops['Range']}")
        print(f"Step_ratio		{param_ops['Step_ratio']}")
        print(f"Intensity_variation 1")
        print(f"Intensity_aging     1")
        print(f"Intensity_distribution 2")
        print(f"Response_prob   1.0")
        print(f"Gnuplot_plots		0")
        sys.stdout = sys.__stdout__

# Resets a lot of the stuff in the directory so you can rerun tests without hiccups
def resetRuntimeDirectory():
    os.system("rm -r Output/run.*/")
    os.system("rm run.num")
    createRunNum()

def load_num() -> int:
    with open("test_scripts/num.txt", "r") as f:
        res = int(f.readline())
    return res


def param_context_manager():
    # Load data from CSV
    test_config = pd.read_csv('test_configs.csv')
    all_params = test_config.values.tolist()
    print_queue = []
    num_runs = load_num()

    # TODO: Remove hard coded values
    # Our param positions from the CSV are hardcoded which is not ideal
    for value_list in all_params:
        param_ops = {
            "Max_steps": value_list[0],
            "Pop_size": value_list[1],
            "Init_thresh": value_list[2],
            "Task_selection": value_list[3],
            "Target_path": value_list[4],
            "Path_period": value_list[5],
            "Path_amplitude": value_list[6],
            "Target_step_len": value_list[7],
            "Range": value_list[8],
            "Step_ratio": value_list[9],
        }
        print_queue.append(param_ops)

    qlen = len(print_queue)
    for i in range(0, qlen):
        print_params(print_queue[i], i)

    valid_paths = {}
    for i in range(0, qlen):
        # Grab the directory string
        folder_path = f"{print_queue[i]['Target_path'].strip()}-{print_queue[i]['Task_selection'].strip()}"
        thresh_path = f"{str(print_queue[i]['Init_thresh']).strip()}"

        # Create the directories 
        os.system(f"mkdir Output/{thresh_path}")
        os.system(f"mkdir Output/{thresh_path}/{folder_path}")

        # Run experiments and move the runs into their respective folder
        for n in range(num_runs):
            os.system(f"./sim params-{i} opfiles")
        

        os.system(f"cp -r Output/run.*/ Output/{thresh_path}/{folder_path}")
        os.system(f"cp -r params-{i} Output/{thresh_path}/{folder_path}")
        resetRuntimeDirectory()

    #os.system("rm ../params-*")
        
# Run the tests
param_context_manager()
