using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TimeStepControl : MonoBehaviour
{
    public GameObject animationControl;
    public GameObject playButton;
    public GameObject nextButton;
    public GameObject prevButton;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void toPlay()
    {

        if(animationControl.GetComponent<AnimationControl>().toPlay == true)
        {
            animationControl.GetComponent<AnimationControl>().toPlay = false;
            playButton.transform.GetChild(1).gameObject.SetActive(true);
            playButton.transform.GetChild(0).gameObject.SetActive(false);
        }
        else
        {
            animationControl.GetComponent<AnimationControl>().toPlay = true;
            playButton.transform.GetChild(0).gameObject.SetActive(true);
            playButton.transform.GetChild(1).gameObject.SetActive(false);
        }
        
    }
}
