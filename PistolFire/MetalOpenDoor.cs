using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OpenMetalDoors : MonoBehaviour
{

    public float theDistance;
    public GameObject leftDoor;
    public GameObject rightDoor;
    public GameObject actionDisplay;
    public GameObject actionText;
    public AudioSource metalOpen;

    // Update is called once per frame
    void Update()
    {
        theDistance = PlayerCasting.distanceFromTarget;
    }

    //if the distance to the target is less than some number, then:
    //1. set the text as active
    //2. have the user press a key on the keyboard
    //3. if that key is down then play our animations
    private void OnMouseOver()
    {
        if (theDistance <= 10)
        {
            actionDisplay.SetActive(true);
            actionText.SetActive(true);

            if (Input.GetButtonDown("Action"))
            {
                metalOpen.Play();
                this.GetComponent<BoxCollider>().enabled = false;
                actionDisplay.SetActive(false);
                actionText.SetActive(false);
                leftDoor.GetComponent<Animator>().Play("LeftSlide");
                rightDoor.GetComponent<Animator>().Play("RightSlide");
            }
        }
    }

    private void OnMouseExit()
    {
        actionDisplay.SetActive(false);
        actionText.SetActive(false);
        
    }

}
