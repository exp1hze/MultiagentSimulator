using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Diagnostics;
using System.IO;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class test : MonoBehaviour
{
    public string result;
    public string state;
    public string ProjectPath;
  
    void Start()
    {
        Scene scene = SceneManager.GetActiveScene();
        if (scene.name.Equals("SetParamForage"))
        {
            ProjectPath = System.IO.Directory.GetCurrentDirectory() + "/Forage";
        }
        else
        {
            ProjectPath = System.IO.Directory.GetCurrentDirectory() + "/Tracker";
        }
    }

    public void run()
    {
        string shell = "run.sh";
        Process process = new Process();
        process.StartInfo.CreateNoWindow = false;
        process.StartInfo.ErrorDialog = true;
        process.StartInfo.UseShellExecute = false;
        process.StartInfo.FileName = "/bin/bash";
        process.StartInfo.Arguments = shell;
        process.StartInfo.RedirectStandardOutput = true;
        process.StartInfo.RedirectStandardInput = true;
        process.StartInfo.WorkingDirectory = ProjectPath;
        process.Start();
        string output = process.StandardOutput.ReadToEnd();
        process.WaitForExit();
        process.Close();
    }

    public void runPath(string name,string path)
    {
        string shell = name;
        ProjectPath += path;
        Process process = new Process();
        process.StartInfo.CreateNoWindow = false;
        process.StartInfo.ErrorDialog = true;
        process.StartInfo.UseShellExecute = false;
        process.StartInfo.FileName = "/bin/bash";
        process.StartInfo.Arguments = shell;
        process.StartInfo.RedirectStandardOutput = true;
        process.StartInfo.RedirectStandardInput = true;
        process.StartInfo.WorkingDirectory = ProjectPath;
        process.Start();
        string output = process.StandardOutput.ReadToEnd();
        process.WaitForExit();
        process.Close();
    }
}
