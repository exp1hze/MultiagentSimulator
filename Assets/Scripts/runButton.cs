using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class runButton : MonoBehaviour
{
    [SerializeField] GameObject[] inputFields;
    [SerializeField] GameObject[] dropdowns;
    //[SerializeField] Camera cam;
    public string readPath;
    public Hashtable _params;
    public string run_num;
    public string runNumPath;
    public GameObject parameterPanel;
    public GameObject animationPanel;
    public GameObject loading;
    Boolean isFinished = false;


    // Start is called before the first frame update
    public GameObject mainCamera;
    void Start()
    {
    
        _params = new Hashtable();
        Scene scene = SceneManager.GetActiveScene();
        if (scene.name.Equals("SetParamForage"))
        {
            readPath = Application.dataPath + "/Forage/params";
            ReadParams(readPath);
            runNumPath = Application.dataPath + "/Forage/run.num";
            ReadRunNum(runNumPath);
        }
        else
        {
            readPath = Application.dataPath + "/Tracker/params";
            ReadParams(readPath);
            runNumPath = Application.dataPath + "/Tracker/run.num";
            ReadRunNum(runNumPath);
        }

    }



    public void ReadRunNum(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        if ((line = sr.ReadLine()) != null)
        {
            run_num = line;
        }
        sr.Close();
    }



    public void ReadParams(string path)
    {
        StreamReader sr = new StreamReader(readPath, Encoding.Default);
        string line;
        while ((line = sr.ReadLine()) != null)          //Read from top to bottom, then put variable name as key, value as value to a hashtable.
        {
            BuildParams(line);
        }
        Debug.Log("-------------------complete--------------");
        //Debug.Log("Rerun : " + _params["Rerun"]);
        sr.Close();
    }

    public void BuildParams(string line)
    {
        string[] param = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
        _params.Add(param[0], param[1]);
        Debug.Log("reading" + param[0] + " " + param[1]);
    }

    // Update is called once per frame
    void Update()
    {   
        if (isFinished == true)
        {
            Scene scene = SceneManager.GetActiveScene();
            if (scene.name.Equals("SetParamForage"))
            {
                ReadRunNum(runNumPath);
                DirectoryInfo dir = new DirectoryInfo(Application.dataPath + "/Forage/Output/run." + run_num);
                if (dir.Exists)
                {

                    animationPanel.SetActive(true);
                    //parameterPanel.SetActive(false);
                    Invoke("ForageAnimationStart", 1.0f);
                    //AnimationStart();
                    isFinished = false;
                }
            }
            else
            {
                ReadRunNum(runNumPath);
                DirectoryInfo dir = new DirectoryInfo(Application.dataPath + "/Tracker/Output/run." + run_num);
                if (dir.Exists)
                {

                    animationPanel.SetActive(true);
                    parameterPanel.SetActive(false);
                    Invoke("AnimationStart", 1.0f);
                    //AnimationStart();
                    isFinished = false;
                }
            }
        }
    }

    public void getFieldText()
    {
       
        loading.SetActive(true);
        string line;
        
        for (int i = 0; i<inputFields.Length; i++)
        {
            string value = inputFields[i].GetComponent<InputField>().text;
            GameObject parent = inputFields[i].transform.parent.gameObject;
            string key = parent.GetComponent<Text>().text;
            //Debug.Log(key+" "+ value);
            if (_params.ContainsKey(key))
            {
                if (!_params[key].Equals(value))
                {
                    _params[key] = value;
                    Debug.Log("the modified key is:" + key + " to value:" + value);
                }
                
            }
        }

        for (int i = 0; i < dropdowns.Length; i++)
        {
            Dropdown dd = dropdowns[i].GetComponent<Dropdown>();
            string value = dd.options[dd.value].text;
            GameObject parent = dropdowns[i].transform.parent.gameObject;
            string key = parent.GetComponent<Text>().text;
            //Debug.Log(key + " " + value);
            if (_params.ContainsKey(key))
            {
                if (!_params[key].Equals(value))
                {
                    _params[key] = value;
                    Debug.Log("the modified key is:" + key + " to value:" + value);
                }
            }
        }

        try
        {
            System.Collections.IDictionaryEnumerator enumerator = _params.GetEnumerator();
            FileStream fs = new FileStream(readPath, FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);
            while (enumerator.MoveNext())
            {
                line = enumerator.Key + "     " + enumerator.Value + "\r\n";
                //Debug.Log(line);
                sw.Write(line);
                sw.Flush();
                
            }

            sw.Close();
            fs.Close();
            Debug.Log("-------------------------");
            mainCamera = GameObject.Find("Main Camera");
            mainCamera.GetComponent<test>().run();
            StartCoroutine(waitImport(10.0f));
            isFinished = true;
            
        }
        catch (IOException)
        {
            Debug.Log("The params file may opened by another program!");
        }
       

    }


    IEnumerator waitImport(float waitTime)
    {
        yield return new WaitForSeconds(waitTime);
    }
    public void AnimationStart()
    {
        // read output file
        string positionFile = Application.dataPath + "/Tracker/Output/run."+run_num+"/run."+run_num+".stepsummary";
        string IRangeFile = Application.dataPath + "/Tracker/Output/run." + run_num + "/run." + run_num + ".intensityranges";
        string TRangeFile = Application.dataPath + "/Tracker/Output/run." + run_num + "/run." + run_num + ".threshrange";
        string IstepFile = Application.dataPath + "/Tracker/Output/run." + run_num + "/run." + run_num + ".stepintensity";
        string TstepFile = Application.dataPath + "/Tracker/Output/run." + run_num + "/run." + run_num + ".stepthresh";
        
        animationPanel.GetComponent<AnimationControl>().AnimationStart(positionFile, IRangeFile, TRangeFile, IstepFile, TstepFile);
        loading.SetActive(false);
    }

    public void ForageAnimationStart()
    {
        // create gnuplot sheldcode script
        int agentnum = 0; int stepnum = 0;
        string positionFilePath = Application.dataPath + "/Forage/Output/run." + run_num + "/gnuplot.sh";
        try
        {
            FileStream fs = new FileStream(positionFilePath, FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);
            string line = "gnuplot run." + run_num + ".agentstepmemory.gnu";
            Debug.Log(line);
            sw.Write(line);
            sw.Flush();

            sw.Close();
            fs.Close();
            

        }
        catch (IOException)
        {
            Debug.Log("The file may opened by another program!");
        }
        string path = "/Output/run." + run_num;

        ReadStepNest(Application.dataPath + "/Forage" + path+"/run."+run_num+".stepnest");


        string name = "gnuplot.sh";
        mainCamera.GetComponent<test>().runPath(name, path);
        LoadTexture2Sprite(run_num, inputFields[2].GetComponent<InputField>().text,
        inputFields[1].GetComponent<InputField>().text);

        animationPanel.GetComponent<AnimationControl>().ForageAnimationStart(run_num.ToString(), inputFields[2].GetComponent<InputField>().text,
        inputFields[1].GetComponent<InputField>().text,loadsprite);
        //loading.SetActive(false);
    }
    ArrayList stepNest_foodin;
    ArrayList stepNest_numactors;
    public void ReadStepNest(string path)
    {
        stepNest_foodin = new ArrayList();
        stepNest_numactors = new ArrayList();
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        while ((line = sr.ReadLine()) != null)    
        {
            BuildStepNest(line);
        }
        Debug.Log("-------------------complete--------------");
        sr.Close();
    }
    
    public void BuildStepNest(string line)
    {
        string[] param = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
        stepNest_foodin.Add(param[3]);
        stepNest_numactors.Add(param[5]);
        Debug.Log("reading" + param[3] + " " + param[5]);
    }
    public List<Sprite> loadsprite;
    // read img to sprite
    private void LoadTexture2Sprite(string runNum, string AgentNum, string StepNum)
    {
        int agentNum = int.Parse(AgentNum);
        int stepNum = int.Parse(StepNum);


        loadsprite = new List<Sprite>();
        for (int i = 0; i < stepNum; i++)
        {
            for (int j = 0; j < agentNum; j++)
            {
                String imgPath = Application.dataPath + "/Forage/Output/run." + runNum + "/run." +
                    runNum + ".agent" + j + ".step" + i + ".memory.png";
                Texture2D t2d = new Texture2D(200, 200);
                t2d.LoadImage(getImageByte(imgPath));
                Sprite sprite = Sprite.Create(t2d, new Rect(0, 0, t2d.width, t2d.height), Vector2.zero);
                loadsprite.Add(sprite);
            }
        }

    }



    // read img byte
    public static byte[] getImageByte(string imagePath)
    {
        FileStream files = new FileStream(imagePath, FileMode.Open);
        byte[] imgByte = new byte[files.Length];
        files.Read(imgByte, 0, imgByte.Length);
        files.Close();
        return imgByte;
    }
}
