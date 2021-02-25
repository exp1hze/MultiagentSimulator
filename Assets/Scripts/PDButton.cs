using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class PDButton : MonoBehaviour
{
    public GameObject childPanel;
    GameObject fatherPanel;
    public GameObject parent;
    public GameObject listPrefab;
                    
    public void gotoSelect(){
        SceneManager.LoadScene("selectFiles");
    }

    public void gotoForageSelect()
    {
        SceneManager.LoadScene("selectForageFiles");
    }
    void Awake()
    {
        GameObject runPath = GameObject.Find("runPath");
        //runPath.GetComponent<runParam>().history = false;
        fatherPanel = GameObject.Find("rightPanel");
        //foreach (Transform child in fatherPanel.transform)
        //{
        //    child.gameObject.SetActive(false);
        //}
    }
    public void onclick()
    {       
        Debug.Log("click");
        foreach (Transform child in fatherPanel.transform)
        {
            
            child.gameObject.SetActive(false);
        }
        childPanel.SetActive(true);
    }

    public void getFileName()
    {
        string filePath = System.IO.Directory.GetCurrentDirectory() + "/Tracker/Output/";
        List<string> allFiles = new List<string>();
        DirectoryInfo dir = new DirectoryInfo(filePath);
        if (!dir.Exists)
        {
            return;
        }

        // get all the output folder names
        foreach (DirectoryInfo subdir in dir.GetDirectories())
        {
            if (!subdir.Name.StartsWith("run"))
            {
                continue;
            }
            //Debug.Log("filename is:" + subdir.Name);
            allFiles.Add(subdir.Name);
            string time = subdir.CreationTime.ToString();
            GameObject listMember = Instantiate(listPrefab);
            listMember.transform.parent = parent.transform;
            listPrefab.GetComponent<Text>().text = subdir.Name + "      " + time;


        }

        
            
       
    }



}
