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
        //Debug.Log(text + "              " + name);
        ShowAlert(name, text);
    }
    string ShowAlert(string name, string text)
    {
        
        switch (name)
        {
            case "ReRun":
                if(!CheckNum(text) && !text.Equals("-1")) {
                    setParam("-1");
                    break;
                }
                int num = int.Parse(text);
                int runNum = int.Parse(button.GetComponent<runButton>().run_num);
                if ( num < -1 || num>runNum)
                {
                    setParam("-1");
                    break;
                }
                ;
                break;

            case "Print_params":
                if (!CheckNum(text))
                {
                    setParam("0");
                    break;
                }

                if(!text.Equals("0") && !text.Equals("1"))
                {
                    setParam("0");
                    Debug.Log("Print_params need 0/1");
                    break;
                }
                break;

            case "Max_steps":
                if (!CheckNum(text))
                {
                    setParam("500");
                    break;
                }

                int num2 = int.Parse(text);
                // what is the upper limit of steps
                if(num2 <= 0)
                {
                    setParam("500");
                }
                break;
            case "Pop_size":
                if (!CheckNum(text))
                {
                    setParam("200");
                    break;
                }

                int num3 = int.Parse(text);
                // what is the upper limit of popsize
                if (num3 <= 0)
                {
                    setParam("500");
                }
                break;
            case "Prob_check":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("1.0");
                    break;
                }

                double s = double.Parse(text);

                //Debug.Log(s);
                if(s<0.0 || s > 1.0)
                {
                    setParam("1.0");
                }
                break;
            case "Target_path":

                break;
            case "Target_step_len":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("3");
                    break;
                }

                double s1 = double.Parse(text);

                //Debug.Log(s);
                if (s1 < 0.0)
                {
                    setParam("3");
                }
                break;
             
            case "Range":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("10");
                    break;
                }

                double s2 = double.Parse(text);

                //Debug.Log(s);
                if (s2 < 0.0)
                {
                    setParam("10");
                }
                break;
            case "Step_ratio":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("2.0");
                    break;
                }

                double s3 = double.Parse(text);

                //Debug.Log(s);
                if (s3 < 0.0)
                {
                    setParam("2.0");
                }
                break;
            default:
                break;
        }
        return name;
    }

    public bool CheckNum(string text)
    {
        string pattern = @"^\d*$";
        if (text.Equals("") || !Regex.IsMatch(text, pattern))
        {
            //gameObject.GetComponent<InputField>().text = "0";
            Debug.Log("need int >= 0");
            return false;
        }
        
        return true;
    }

    public void setParam(string s)
    {
        gameObject.GetComponent<InputField>().text = s;
    }
}
