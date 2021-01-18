using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;

public class Tooltip : MonoBehaviour, IPointerEnterHandler, IPointerExitHandler
{
    private GameObject tooltip;
    public void OnPointerEnter(PointerEventData eventData)
    {
        string key = transform.parent.GetComponent<Text>().text;
        Scene scene = SceneManager.GetActiveScene();
        if(scene.name.Equals("SetParamTracker"))
        {
            (tooltip.transform.GetChild(0)).GetComponent<Text>().text = GetTrackerInfo(key);
        }
        else if (scene.name.Equals("SetParamForage"))
        {
            (tooltip.transform.GetChild(0)).GetComponent<Text>().text = GetForageInfo(key);
        }
        
      
        tooltip.SetActive(true);
        tooltip.transform.position = this.transform.position;
        tooltip.transform.SetAsLastSibling();
        
        //Debug.Log(key);
    }

    public void OnPointerExit(PointerEventData eventData)
    {
        tooltip.SetActive(false);
    }

    string GetTrackerInfo(string key)
    {
        switch(key)
        {
            case "Rerun":
                key = "(integer) - If set to -1, generate a new random seed for the current run. If greater than -1, use the random seed from run number <Rerun> which is stored in the file< Output path >/ run.< Rerun >/ run.< Rerun >.random.Despite using a previous run’s random seed, the current run is still assigned a new run number of its own based on the current value in the file run.num.";
                break;
            case "Print_params":
                key = "(integer) - If equal to one, print run parameters to screen at start of run. Don’t, if equal to zero.";
                break;
            case "Max_steps":
                key = "(integer) - Maximum number of timesteps to run the simulation.";
                break;
            case "Pop_size":
                key = "(integer) - Number of agents in the population.";
                break;
            case "Prob_check":
                key = "(double) - Double value ranging from 0.0 to 1.0. Probability that agent will stop to reconsider what task to work on. If the agent does not stop to reconsider, then continues with current task. Right now this value applies to all agents in the population. \nEventually may consider revising code such that 0.0 causes all agents to be individually assigned a randomly generated prob check value so that agents can have different likelihoods of stopping to reconsider what task to work on.";
                break;
            case "Target_path":
                key = "(char *) - Specify the target path. Current choices include:\n– square\n– square10\n– circle\n– random\n– random manhattan";
                break;
            case "Target_step_len":
                key = "(double) - Distance that target travels in one timestep.";
                break;
            case "Range":
                key = "(double) - This parameter indicates the distance to either side of the center of the distribution that threshold values will run. In other words, the range of threshold for a task, e.g. push north, is 2×Range and all agents will act if the stimulus is greater than 2×Range. Opposite tasks, e.g. pushing north and south have adjacent ranges.\nFor example, if Range = 10, then push north thresholds range from zero to 20 as do push south thresholds, and the two ranges are adjacent at zero. As a result, all agents will act if the stimulus is greater than 20. (Caveat: all agents will act only if no other stimuli are active. If other stimuli are active, then some agents may act on other tasks.)";
                break;
            case "Step_ratio":
                key = "(double) - Ratio of the tracker’s maximum step length to the target’s step length. For example, Step ratio=2.0 means that the maximum distance that the tracker can travel in one timestep is twice the target’s step length or 2.0×Target step len.";
                break;
            case "Task_selection":
                key = "(char *) - If more than one task demand exceeds an agent’s corresponding task thresholds, this parameter determines how the agent selects a task to work on. Two select methods are currently implemented: \n–  random\n–  urgent";
                break;
            default:
                break;
        }
        return key;
    }
    string GetForageInfo(string key)
    {
        switch (key)
        {
            case "Rerun":
                key = "(integer) - If set to -1, generate a new random seed for the current run. If greater than -1, use the random seed from run number <Rerun> which is stored in the file< Output path >/ run.< Rerun >/ run.< Rerun >.random.Despite using a previous run’s random seed, the current run is still assigned a new run number of its own based on the current value in the file run.num.";
                break;
            case "Max_steps":
                key = "(integer) - Maximum number of timesteps to run the simulation.";
                break;
            case "Pop_size":
                key = "(integer) - size of population space";
                break;
            case "Init_thresh":
                key = "How to initialize the thresholds of the agents in the population: Values range from 0.0 to 1.0, if 0.0 = initialize randomly else initialize all thresholds to the given value";
                break;
            case "Max_thresh":
                key = "maximum values that agent thresholds can reach";
                break;
            case "Min_thresh":
                key = "minimum values that agent thresholds can reach";
                break;
            case "Prob_check":
                key = "Probability that agent will stop to reconsider what task to work on.\nIf the agent does not stop to reconsider, then continues with current task. This parameter determines how agents will be assigned their own individual value of Agent[].prob_check. Values assigned to agents will range from 0.0 to 1.0, if 0.0 = initialize randomly else initialize all thresholds to the given value Once the agents have their own values for this parameter, it will determine the probability of them stopping to check for new tasks. For values of Agent[].prob_check lower than 0.1, the probability with which the agent stops to check will vary randomly in each timestep.";
                break;
            case "Grid_height":
                key = "Environment parameters";
                break;
            case "Grid_width":
                key = "Environment parameters";
                break;
            case "Num_food":
                key = "Environment parameters";
                break;
            case "Init_food":
                key = "Indicate how food locations will be set up.  'random' randomly generates locations.  Any other input will be considered the file name from which to read 'Num_food' (first) and the row and col of each source (1 on each line). Does not check that user enters valid row/col values.";
                break;
            case "Need":
                key = "Number of agents that need to act in each timestep.  Basically, one timestep is one instance of the task and Need is the number of agents that need to act in order to meet the demands of the task.";
                break;
            case "Response_prob":
                key = "response probability: right now all agents get the same value. value ranges from 0.0 to 1.0 might want to set up random later";
                break;
            case "Max_sim_time":
                key = "Maximum timesteps each time an agent searches for food. Max timestep of agents' individual runs.";
                break;
            case "Positive_reinforcement":
                key = "The reinforcement values range from 0.0 (no reinforcement) to 1.0 max. Positive reinforcement means that cells in a path that does lead to food will become more likely to selected for future paths.";
                break;
            case "Negative_reinforcement":
                key = "Negative reinforcement means that cells in a path that does not lead to food will be less likely to be selected for future paths.";
                break;
            default:
                break;
        }
        return key;
    }

    void Start()
    {
        tooltip = GameObject.Find("Canvas").transform.Find("Tooltip").gameObject;
        //Debug.Log(tooltip.transform.GetChild(0).GetComponent<Text>().text);
    }
}
