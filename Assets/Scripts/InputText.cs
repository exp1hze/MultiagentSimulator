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

            // Forage
            case "Init_thresh":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("0");
                    break;
                }

                double s4 = double.Parse(text);

                //Debug.Log(s);
                if (s4 < 0.0 || s4 > 1.0)
                {
                    setParam("0");
                }
                break;

            case "Max_thresh":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("1.0");
                    break;
                }

                double s5 = double.Parse(text);

                //Debug.Log(s);
                if (s5 < 0.0 || s5 > 1.0)
                {
                    setParam("1.0");
                }
                break;

            case "Min_thresh":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("0");
                    break;
                }

                double s6 = double.Parse(text);

                //Debug.Log(s);
                if (s6 < 0.0 || s6 > 1.0)
                {
                    setParam("0");
                }
                break;

            case "Grid_height":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("100");
                    break;
                }

                double s7 = double.Parse(text);

                //Debug.Log(s);
                if (s7 < 0.0)
                {
                    setParam("100");
                }
                break;

            case "Grid_width":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("100");
                    break;
                }

                double s8 = double.Parse(text);

                //Debug.Log(s);
                if (s8 < 0.0)
                {
                    setParam("100");
                }
                break;

            case "Need":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("20");
                    break;
                }

                double s9 = double.Parse(text);

                //Debug.Log(s);
                if (s9 < 0.0)
                {
                    setParam("20");
                }
                break;

            case "Response_prob":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("1.0");
                    break;
                }

                double rp = double.Parse(text);

                //Debug.Log(s);
                if (rp < 0.0 || rp > 1.0)
                {
                    setParam("1.0");
                }
                break;

            case "Max_sim_time":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("1000");
                    break;
                }

                double mst = double.Parse(text);

                //Debug.Log(s);
                if (mst < 0.0)
                {
                    setParam("1000");
                }
                break;

            case "Positive_reinforcement":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("0.3");
                    break;
                }

                double pos_r = double.Parse(text);

                //Debug.Log(s);
                if (pos_r < 0.0 || pos_r > 1.0)
                {
                    setParam("0.3");
                }
                break;

            case "Negative_reinforcement":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("0.3");
                    break;
                }

                double neg_r = double.Parse(text);

                //Debug.Log(s);
                if (neg_r < 0.0 || neg_r > 1.0)
                {
                    setParam("0.3");
                }
                break;

            case "Num_food":
                if (!CheckNum(text) && !Regex.IsMatch(text, "^([0-9]{1,}[.][0-9]*)$"))
                {
                    setParam("4");
                    break;
                }

                double food = double.Parse(text);

                //Debug.Log(s);
                if (food < 0.0)
                {
                    setParam("4");
                }
                break;
                case "Init_food":
                if(!System.IO.File.Exists(System.IO.Directory.GetCurrentDirectory() + "/Forage/" + text))
                {
                    (GameObject.Find("Canvas").transform.Find("foodNFWindow")).gameObject.SetActive(true);
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
