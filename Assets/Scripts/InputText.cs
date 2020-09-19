using System.Collections;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using UnityEngine;
using UnityEngine.UI;

public class InputText : MonoBehaviour
{
    [SerializeField] GameObject button;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void checkInput()
    {
        string text = gameObject.GetComponent<InputField>().text;
        
        string name = gameObject.name;
        Debug.Log(text + "              " + name);
        ShowAlert(name, text);
    }
    string ShowAlert(string name, string text)
    {
        switch (name)
        {
            case "ReRun":
                
                string pattern = @"^\d*$";
                if(!Regex.IsMatch(text, pattern) && !text.Equals("-1")) {
                    gameObject.GetComponent<InputField>().text = "-1";
                    Debug.Log("wrong");
                    break;
                }

                int num = int.Parse(text);
                int runNum = int.Parse(button.GetComponent<runButton>().run_num);
                if ( num >= -1 && num<=runNum)
                {
                    Debug.Log("----------" + num);
                    break;
                }
                gameObject.GetComponent<InputField>().text = "-1";
                break;
            case "Print_params":
                break;
            case "Max_steps":
                break;
            case "Pop_size":
                break;
            case "Prob_check":
                break;
            case "Target_path":
                break;
            case "Target_step_len":
                break;
            case "Range":
                break;
            case "Step_ratio":
                break;
            default:
                break;
        }
        return name;
    }
}
